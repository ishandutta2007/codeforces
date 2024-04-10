#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
	AquA;
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int j=0;j<n;j++){
		cin >> b[j];
	}
	if(n==1){
		if(a[0]==b[0]){
			cout << "SMALL\n" << 0 << "\n\n";
		}
		else{
			cout << "IMPOSSIBLE\n";
		}
		return 0;
	}
	if(n==2){
		string s="";
		int cnt=0,c2=0;
		while(1){
			if(a==b){
				break;
			}
			auto c=a;
			reverse(c.begin(),c.end());
			if(c==b){
				cnt++;
				s+='R';
				break;
			}
			if(b[0]==0 || b[1]==0){
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			if(b[0]>b[1]){
				cnt++;
				if(cnt<=2e5){
					s+='R';
				}
				swap(b[0],b[1]);
			}
			else{
				if(a[0]==b[0]){
					if(b[1]%a[0]==a[1]%a[0]){
						cnt+=(b[1]-a[1])/a[0];
						c2+=(b[1]-a[1])/a[0];
						if(cnt<=5e5){
							for(int i=0;i<(b[1]-a[1])/a[0];i++){
								s+='P';
							}
						}
						break;
					}
				}
				if(c[0]==b[0]){
					if(b[1]%c[0]==c[1]%c[0]){
						cnt+=(b[1]-c[1])/c[0];
						c2+=(b[1]-c[1])/c[0];
						if(cnt<=5e5){
							for(int i=0;i<(b[1]-c[1])/c[0];i++){
								s+='P';
							}
						}
						cnt++;
						s+='R';
						break;
					}
				}
				cnt+=(b[1]/b[0]);
				c2+=(b[1]/b[0]);
				if(cnt<=5e5){
					for(int i=0;i<b[1]/b[0];i++){
						s+='P';
					}
				}
				b[1]%=b[0];
			}
		}
		if(c2>2e5){
			cout << "BIG" << "\n" << c2 << "\n";
		}
		else{
			cout << "SMALL\n";
			cout << cnt << "\n";
			reverse(s.begin(),s.end());
			cout << s << "\n";
		}
	}
	else{
		int cnt=0,c2=0;
		auto c=a;
		reverse(c.begin(),c.end());
		vector<char> s;
		while(1){
			if(a==b){
				break;
			}
			if(c==b){
				cnt++;
				s.push_back('R');
				break;
			}
			int inc=1,dnc=1;
			for(int i=0;i<n-1;i++){
				if(b[i]<=0){
					cout << "IMPOSSIBLE\n";
					return 0;
				}
				if(b[i]>b[i+1]){
					inc=0;
				}
				else if(b[i]<b[i+1]){
					dnc=0;
				}
			}
			if(b[n-1]<=0){
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			if(!inc && !dnc){
				cout << "IMPOSSIBLE" << "\n";
				return 0;
			}
			if(inc){
				cnt++;
				c2++;
				if(cnt<=5e5){
					s.push_back('P');
				}
				for(int i=n-1;i>0;i--){
					b[i]-=b[i-1];
				}
			}
			else{
				cnt++;
				if(cnt<=5e5){
					s.push_back('R');
				}
				reverse(b.begin(),b.end());
			}
		}
		if(c2>2e5){
			cout << "BIG\n" << c2 << "\n";
		}
		else{
			cout << "SMALL\n";
			cout << cnt << "\n";
			reverse(s.begin(),s.end());
			for(auto h:s){
				cout << h;
			}
			cout << "\n";
		}
	}
	return 0;
}