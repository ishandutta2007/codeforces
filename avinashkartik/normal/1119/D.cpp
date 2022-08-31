#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
ll bs(ll a[],ll val,int n){
    int u = 0;
    int v = n;
    int mid;
    ll res = -1;
    while(u <= v){
	int mid = (u + v) / 2;
	//cout<<mid<<" "<<a[mid]<<" "<<val<<" ";
			if(a[mid] <= val) {
				res = mid;
				u = mid + 1;
			} else v = mid - 1;
    }
    return(res);
}


int main(){
	ll n,q,a[100005];
	cin>>n;
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll l,r;
	if(n>1){
	    ll b[100005],pre[100005];
	    for(int i =1;i<n;i++){
	        b[i] = (a[i]-a[i-1]);
	    	//cout<<b[i];
	    }
	    sort(b,b+n);
	    //cout<<pre[0]<<" ";
	    for(int i =1;i<n;i++){
	        pre[i] = b[i]+pre[i-1];
	    	//cout<<pre[i]<<" ";
	    }
	    //cout<<endl;
	    cin>>q;
	    for(int i = 0;i<q;i++){
	        cin>>l>>r;
	        ll d = r-l;
	        //cout<<"d: "<<d<<" ";
	            int ind = bs(b,d,n-1);
	            //cout<<"ind : "<<ind<<" ";
	            ll s = pre[ind] + (n-ind)*(d+1);
	            cout<<s<<" ";
	        
	    }
	}
	else{
	    cin>>q;
	    for(int i = 0;i<q;i++){
	        cin>>l>>r;
	        ll d = r-l+1;
	        cout<<d<<" ";
	    }
	}
}