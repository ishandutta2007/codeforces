#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;

char ch;
int n,m;
char tmp1,tmp2,tmp3;

int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>tmp2;
    	if (i!=0 && tmp1==tmp2){
            cout<<"NO"<<endl;
            return 0;
        }
        for (int j=1;j<m;j++){
        	cin>>tmp3;
        	if (tmp2!=tmp3){
        		cout<<"NO"<<endl;
        		return 0;
			}
		}
		tmp1=tmp2;
    }
    cout<<"YES"<<endl;
    return 0;
}