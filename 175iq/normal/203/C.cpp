#include <iostream>
#include <fstream>
#include <algorithm>
 
using namespace std;
 
/*struct cl{
		int no, m;
};*/
 
/*inline bool cmp(cl a,cl b){
 
		return a.m < b.m;
}
*/
pair <int,int> client[100000+5];
 
int main(){
 
		ios_base::sync_with_stdio(0);
 
		//cout<<"*************OUTPUT BY FILE************"<<endl;
		//ifstream cin("input.txt");
 
		int n,d,a,b;
 
		cin>> n >> d >> a >> b;
 
		//cl client[1000+5];
		
		int x,y;
		for(int i=1;i<=n;i++)
		{
				cin>> x >> y;
				client[i].second = i;
				client[i].first = x * a + y * b;
		}
 
		sort(client+1,client+n+1);
 
		int cnt = 1;
		
		while(d>=0 && cnt<=n)
		{
				d -= (client[cnt].first);
				cnt ++;
		}
		
		cnt--;
		if(d<0)
				cnt--;
 
		cout<< cnt << "\n";
		while(cnt){
				cout<< client[cnt].second << " ";
				cnt--;
		}
 
		return 0;
}