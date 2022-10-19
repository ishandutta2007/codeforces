#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

int a[200001];
bool b[200001];
bool c[200001];
long long mod = 1000000007;

int find(int i){
	
	if(a[i]!=i){
		a[i] = find(a[i]);
	}
	return a[i];
}

void unio(int x, int y){
   a[find(x)] = find(y);
}





int main() {
	int n;
	 cin >> n;
	 for(int i=1; i<=2*n; i++){
	 	a[i] = i;
	 }
	 
	 for(int i=0; i<n; i++){
	 	int x, y;
	 	cin >> x >> y;
	 	unio(x, y);
	 	
	 	b[x] = true;
	 	if(x==y){
	 		c[x] = true;
	 	}
	 }
	 
	 map<int, long long> m;
	 map<int, long long> nn;
	 map<int, long long> kk;
	 for(int i=1; i<=2*n; i++){
	 	m[find(i)]++;
	 	if(b[i]){
	 		nn[find(i)]++;
	 	}
	 	if(c[i]){
	 		kk[find(i)]++;
	 	}
	 }
	 long long total = 1;
	 
	 for(auto p : m){
	 	if(kk[p.first]) continue;
	 	long long x = p.second;
	 	long long y = nn[p.first];
	 	if(x==y) {
	 		total*=2;
	 		total%=mod;
	 	}
	 	else{
	 		total*=x;
	 		total%=mod;
	 	}
	 }	
	 cout << total << endl;
	 
}