#include<bits/stdc++.h>
using namespace std;

int T , N , arr[300003];

int main(){
	cin >> T;
	while(T--){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
		int fir = 0 , lst = 0;
		for(int i = 1 ; i < N ; ++i)
			if(arr[i] == arr[i + 1]){
				if(!fir) fir = i + 1;
				lst = i;
			}
		if(fir > lst || !fir) cout << 0 << endl;
		else cout << max(1 , lst - fir) << endl;
	}
	return 0;
}