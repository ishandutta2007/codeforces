#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	int n,i,j,tmp,ttmp,min=2147483647;
	string s[50],ss[50]={""};
	char t;
	scanf("%d",&n);
	for(i=0;i<n;i++) cin >> s[i];
	for(i=0;i<n;i++)
		for(j=s[i].size()-1;j>=0;j--) ss[i]+=s[i][j];
	for(i=0;i<n;i++)
	{
		//printf("use ss[%d]\n",i);
		for(j=0,tmp=0;j<n;j++)
		{
			s[j]=ss[j],ttmp=0;//,cout << s[j];
			while(ttmp<ss[i].size() && s[j]!=ss[i]) t=s[j].back(),s[j].pop_back(),s[j]=t+s[j],ttmp++;//,cout << " " << s[j];
			//cout << " " << ttmp << "\n";
			if(ttmp==ss[i].size()) break;
			tmp+=ttmp;
		}
		if(ttmp==ss[i].size()) break;
		ttmp=0;
		if(tmp<min) min=tmp;
	}
	if(ttmp) printf("-1\n");
	else printf("%d\n",min);
}