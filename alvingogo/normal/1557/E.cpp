#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << 1 << " " << 8 << endl;
        string tmp;
        cin >> tmp;
        if(tmp=="Done"){
            continue;
        }
        int flag=0;
        for(int i=1;i<=8;i++){
            while(1){
                int flag2=0,flag3=0;
                for(int j=1;j<=8;j++){
                    cout << i << " " << j << endl;
                    string a;
                    cin >> a;
                    if(a=="Done"){
                        flag=1;
                        break;
                    }
                    int dx=0;
                    if(a[0]=='U'){
                        dx=-1;
                    }
                    if(a[0]=='D'){
                        dx=1;
                    }
                    if(dx==0){
                        continue;
                    }
                    if(dx==1){
                        flag2=j;
                        break;
                    }
                    else{
                        flag3=1;
                    }
                }
                if(flag){
                    break;
                }
                if(flag2 || !flag3){
                    int k=8;
                    if(flag2){
                        k=flag2;
                    }
                    if(k==1){
                        k=2;
                    }
                    cout << i+1 << " " << k << endl;
                    int nw=i+1;
                    while(1){
                        string a;
                        cin >> a;
                        if(a=="Done"){
                            flag=1;
                            break;
                        }
                        if(a[0]=='D'){
                            nw++;
                            cout << nw << " " << k << endl;
                        }
                        else{
                            break;
                        }
                    }
                    i=nw-1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
    }
    return 0;
}