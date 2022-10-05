#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+12,inf=1e9,LOG=18,block=316;
string s,t;
int m,ans,mx[maxn],mn[maxn];
vector<int> z_func (string s) {
	int n = (int) s.size();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
string rev(string s){
	for(int i=0;i<s.size()/2;i++)
		swap(s[i],s[s.size()-1-i]);
	return s;
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
 	#endif
 	IOS
 	cin>>s;
	cin>>m;
	while(m--){	
		cin>>t;
		vector<int> z;
		//mn       0#1
		z=z_func(t+'#'+s);
		for(int i=0;i<=1500;i++)
			mn[i]=1e9;
		
		for(int i=0;i<s.size();i++)	
		    mn[ z[i+t.size()+1] ]=min(mn[ z[i+t.size()+1] ] , i );
		for(int i=t.size();i>=0;i--)
			mn[i]=min(mn[i],mn[i+1]);
        //mx
		z=z_func(rev(t)+'#'+rev(s));
		for(int i=0;i<=1500;i++)
			mx[i]=-1e9;
		for(int i=0;i<s.size();i++)	
			mx[ z[i+t.size()+1] ]=max(mx[ z[i+t.size()+1] ] , (int)s.size()-i+1 );
		for(int i=t.size();i>=0;i--)
			mx[i]=max(mx[i],mx[i+1]);       
    	/*
    	for(int i=1;i<=t.size();i++)
    		cout<<mn[i]<<" ";cout<<endl;

    	for(int i=1;i<=t.size();i++)
    		cout<<mx[i]<<" ";cout<<endl;
    	*/
    	// ans
    	for(int i=1;i<t.size();i++){
    		int len1=i,len2=t.size()-i;
    		if( mx[len2]-mn[len1]>(int)t.size() ){
    			ans++;
    			break;
    		}
    	}
    }
	cout<<ans;
}