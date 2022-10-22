#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2000;
int n;
struct re{
	int a,b,c;
	bool operator <  (const re x) const{
		return a<x.a;
	}
};
vector<re> ve;
int M[N][N],a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i){
    	cin>>a[1]>>a[2]>>a[3]>>a[4];
    	sort(a+1,a+4+1);
    	cout<<a[1]*a[3]<<'\n';
    }
	return 0;
}