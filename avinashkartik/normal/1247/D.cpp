#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
#define MAXN 10000001

int spf[MAXN]; 

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 
  
ll n,k,ct,ans;
ll a[100005];
map <vector<pair<ll,ll>>,ll> D;

int main(){ 
    sieve(); 
    cin>>n>>k;
  	for (int i=0; i<n; i++){
  		cin>>a[i];
    	vector <int> p = getFactorization(a[i]); 
  		map <ll,ll> d;
		ll N = p.size();
		for (int i=0; i<N; i++)
		    d[p[i]] += 1;
		vector<pair<ll,ll>> L;
		for(auto it : d){
		    if(it.second%k != 0)
		        L.push_back({it.first,it.second%k});
		}
		if(L.size() == 0) ct += 1;
		else D[L]++;
	}
	for(auto it : D){
		vector<pair<ll,ll>> newv;
		for(auto it1 : it.first){
			//cout<<it1.first<<" "<<it1.second;
			newv.push_back({it1.first,k-it1.second});
		}
		ans += D[newv]*D[it.first];
		if(newv == it.first){
			ans -= D[newv];
		}
		//cout<<" "<<it.second<<endl;
	}
	ans /= 2;
	ans += (ct*(ct-1))/2;
	cout<<ans;
}