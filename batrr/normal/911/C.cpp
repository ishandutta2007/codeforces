#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
const int maxn=1e5+123;
int a,b,c;
bool check(int i,int j){
	int start=max(i,j);
	for(int q=start;q<start+100;q++){
		if(q%a==0 || (q-i)%b==0 || (q-j)%c==0)
			continue;
		return false;
	}
	return true;
}
int main(){                                                  
	cin>>a>>b>>c;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(check(i,j)){
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
}