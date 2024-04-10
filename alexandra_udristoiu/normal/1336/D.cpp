#include<iostream>
using namespace std;
int n, i, j, ct, cs, pt, ps, x;
int v[105], z[105];
int main(){
    cin>> n >> pt >> ps;
    cout<<"+ 1\n";
    cout.flush();
    cin>> ct >> cs;
    if(ct != pt){
        for(i = 2; i <= n; i++){
            if(i * (i - 1) / 2 == ct - pt){
                v[1] = i + 1;
                break;
            }
        }
    }
    else{
       z[1] = 1;
    }
    pt = ct; ps = cs;
    cout<<"+ 2\n";
    cout.flush();
    cin>> ct >> cs;
    if(cs == ps){
        z[3] = 1;
    }
    for(i = 3; i < n; i++){
        pt = ct; ps = cs;
        cout<<"+ "<< i <<"\n";
        cout.flush();
        cin>> ct >> cs;
        if(ct == pt){
            if(z[i] == 1){
                v[i] = 1;
            }
            else{
                v[i] = 2;
            }
        }
        else{
            for(j = 2; j <= n; j++){
                if( j * (j - 1) / 2 == ct - pt){
                    v[i] = j + 1;
                    break;
                }
            }
        }
        if(i == 3){
            x = cs - ps;
            ps = cs; pt = ct;
            cout<<"+ 1\n";
            cout.flush();
            cin>> ct >> cs;
            if(z[1] == 1){
                if(ct == pt){
                    v[1] = 2;
                }
                else{
                    v[1] = 3;
                }
            }
            else{
                v[1]++;
            }
            v[2] = (cs - ps) / v[3];
            if(x == v[2] * (v[1] - 1) ){
                z[4] = 1;
            }
        }
        else if(cs == ps + v[i - 1] * v[i - 2]){
            z[i + 1] = 1;
        }
    }
    for(i = 1; i < n - 2; i++){
        cs -= v[i] * v[i + 1] * v[i + 2];
    }
    v[n] = cs / v[n - 1] / v[n - 2];
    v[1]--;
    for(i = 1; i < n; i++){
        v[i]--;
    }
    cout<<"! ";
    for(i = 1; i <= n; i++){
        cout<< v[i] <<" ";
    }
}