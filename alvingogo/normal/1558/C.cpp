#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);cout.tie(0);

using namespace std;

int n;
vector<int> v;
void rev(int a){
	for(int i=0;i<a/2;i++){
		swap(v[i],v[a-i]);
	}
}
int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		v.resize(0);
		v.resize(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		int flag=0;
		for(int i=0;i<n;i++){
			if(v[i]%2==i%2){
				flag=1;
			}
		}
		if(flag){
			cout << -1 << "\n";
			continue;
		}
		vector<int> z;
		for(int i=n-1;i>=0;i-=2){
			if(v[i]!=i+1 || (i>0 && v[i-1]!=i)){
				int b=0,c=0;
				for(int j=0;j<=i;j++){
					if(v[j]==i+1){
						b=j;
					}
				}
				rev(b);
				for(int j=0;j<=i;j++){
					if(v[j]==i){
						c=j;
					}
				}
				rev(c-1);
				rev(c+1);
				rev(2);
				rev(i);
				z.push_back(b+1);
				z.push_back(c);
				z.push_back(c+2);
				z.push_back(3);
				z.push_back(i+1);
			}
		}
		cout << z.size() << "\n";
		for(int i=0;i<z.size();i++){
			cout << z[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}