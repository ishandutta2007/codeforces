#include<iostream>

using namespace std;

const long long mod=1e9+7;

main(){
    int n;
    cin>>n;
    long long dp[5003];
    long long L[5003];
    for (int i=0;i<5003;i++){
    	L[i]=0;
	}
    char ch,last;
    cin>>ch;
    last=ch;
    dp[0] = 1;
    for(int i=1 ;i<n;i++){
        cin >> ch;
        if(last=='f'){
            if(ch=='f'){
                for(int j=0;j<=i;j++){
                    L[j+1]=dp[j];
                }
            }
			else {
                for(int j=0;j<5003;j++){
                    L[j+1]=dp[j];
                }
            }
        } 
		else {
            for(int j=i+2;j>=0;j--) {
                L[j]=(dp[j]+L[j+1])%mod;
            }
        }
        last=ch;
        for(int j=0;j<5003;j++){
            dp[j]=L[j];
            L[j]=0;
        }
    }
    long long out=0;
    for(int i =0;i<5003;i++){
        out=(out+dp[i])%mod;
    }
    cout << out <<endl;
}