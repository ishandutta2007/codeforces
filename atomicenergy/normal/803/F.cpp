#include <iostream>
#include <vector>
using namespace std;

int freq[100001];
int tot[100001];
int nums[100000];
int all[100000];
long long mod = 1000000007;

long long solve(int k){
	if(k==0) return 0;
	if(k==1) return 1;
	long long l = solve(k/2)+1;
	if(k%2==0) return (l*l-1)%mod;
	return (l*l*2-1)%mod;
}

int get(int i,int j){
	int k = 0;
	while(i%j==0){
		k++;
		i/=j;
	}
	return k;
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<100001; i++){
		freq[i] = 0;
		tot[i] = 0;
		all[i] = 0;
	}
	tot[0] = 0;
	tot[1] = 0;
	for(int j=2; j<100001; j++){
		if(tot[j] == 0){
			
			for(int i=j; i<100001; i+=j){
				tot[i] += 1;
				if(i%(j*j)==0){
					all[i] += 1;
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		cin >> nums[i];
		for(int j=1; j*j<=nums[i]; j++){
			if(nums[i]%j==0){
				freq[j]++;
				if(j*j!=nums[i]){
					freq[nums[i]/j]++;
				}
			}
		}
	}
	long long t = 0;
	for(int i = 1; i<=100000; i++){
		//cout << i << " " << freq[i] << " " << tot[i] << " " << solve(freq[i]) << endl;
		if(all[i]==0){
		if(tot[i]%2==1){
			t-=solve(freq[i]);
			t+=mod;
			t%=mod;
		}
		else{
			t+=solve(freq[i]);
			t+=mod;
			t%=mod;
		}
		}
	}
	cout << t << endl;
}