#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,a,b,c,d,k;
int main()
{
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b>>c>>d>>k;
		int pd=0;
		for(int x=0;x<=k;x++){
			int y=k-x;
			if(x*c>=a&&y*d>=b){
				cout<<x<<" "<<y<<endl;
				pd=1;
				break;
			}
		}
		if(!pd)cout<<"-1\n";
	}
    return 0;
}