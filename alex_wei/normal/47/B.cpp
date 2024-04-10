#include<bits/stdc++.h>
using namespace std;
struct node{
	int p;
	char x;
}z[3];
bool cmp(node a,node b){return a.p<b.p;}
char a,b,c;
int main()
{
	for(int i=0;i<3;i++){
		z[i].x=i+'A';
		cin>>a>>c>>b;
		if(c=='>')swap(a,b);
		z[a-'A'].p++;
		z[b-'A'].p+=2;
	}
	sort(z,z+3,cmp);
	if(z[0].p==z[1].p||z[1].p==z[2].p)
		cout<<"Impossible",exit(0);
	for(int i=0;i<3;i++)
		cout<<z[i].x;
    return 0;
}