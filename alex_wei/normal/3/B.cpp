#pragma GCC optimize(3)
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sort(x) sort(all(x))
#define rev(x) reverse(all(x))

int n,v,ans,w;
vector <pii> a,b;
int main(){
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		int t,p;
		cin>>t>>p;
		if(t==1)a.pb({p,i});
		else b.pb({p,i});
	}
	sort(a),sort(b);
	rev(a),rev(b);
	for(int i=1;i<a.size();i++)a[i].fi+=a[i-1].fi;
	for(int i=1;i<b.size();i++)b[i].fi+=b[i-1].fi;
	for(int i=0;i<=a.size()&&i<=v;i++){
		int rem=min((v-i)/2,(int)b.size());
		int val=(i>0?a[i-1].fi:0)+(rem>0?b[rem-1].fi:0);
		if(val>ans)ans=val,w=i;
	}
	cout<<ans<<endl;
	for(int i=0;i<w;i++)cout<<a[i].se<<" ";
	int rem=min((v-w)/2,(int)b.size());
	for(int i=0;i<rem;i++)cout<<b[i].se<<" ";
    return 0;
}