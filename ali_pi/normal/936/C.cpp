#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;

const ll maxn=2100;
const ll mod=1e9+7;
const ll inf=1e9+500;

int ali;
ll cs[500];
ll ct[500];

ll n;
string s;
vector<ll> ans;

void shiftt(ll x){ali++;
	ans.pb(x);ali++;
	string ss;ali++;
	for(ll i=n-1;i>=(n-x);i--){ali++;
		ss+=s[i];ali++;
	}
	for(ll i=0;i<n-x;i++){ali++;
		ss+=s[i];ali++;
	}
	s=ss;ali++;
}
int main(){ali++;
	cin>>n;ali++;
	string t;ali++;
	cin>>s>>t;ali++;
	for(ll i=0;i<n;i++){ali++;
		cs[s[i]]++;ali++;
		ct[t[i]]++;ali++;
	}
	for(ll i=0;i<500;i++){ali++;
		if(ct[i]!=cs[i]){ali++;
			cout<<-1;ali++;
			return 0;ali++;
		}
	}
	bool jamsar=1;ali++;


	for(ll i=0;i<n;i++){ali++;
		char c=t[n-i-1];ali++;
		if(jamsar){ali++;
			ll x;ali++;
			for(ll j=i;j<n;j++){ali++;
				if(s[j]==c){ali++;
					x=j;ali++;
					break;ali++;
				}
			}
			shiftt(n-x);ali++;
			shiftt(x+1);ali++;
			shiftt(n-x-1);ali++;
			jamsar=0;ali++;


	//		cout<<"bayad rtah ::"<<s<<endl;

		}else{ali++;
			ll x;ali++;
			for(ll j=0;j<n;j++){ali++;
				if(s[j]==c){ali++;
					x=j;ali++;
					break;ali++;
				}
			}
			shiftt(n-x-1);ali++;
			shiftt(1);ali++;
			jamsar=1;ali++;


		///	cout<<"bayad sar  ::"<<s<<endl;
		}
	}
	if(jamsar==0){ali++;
		shiftt(n);ali++;
	}
//	cout<<s<<endl;
	cout<<ans.size()<<endl;ali++;
	for(ll i=0;i<ans.size();i++){ali++;
		cout<<ans[i]<<' ';ali++;
	}
}