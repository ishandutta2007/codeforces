#include<iostream>
using namespace std;
int q, i, j, ii;
long long a, b, m, r[55], pt[55], x;
int main(){
    cin>> q;
    pt[0] = 1;
    for(i = 1; i <= 50; i++){
        pt[i] = pt[i - 1] * 2;
    }
    for(; q; q--){
        cin>> a >> b >> m;
        if(a == b){
            cout<<"1 "<< a <<"\n";
            continue;
        }
        for(i = 2; i <= 50; i++){
            if(pt[i - 2] * a + pt[i - 2] <= b && pt[i - 2] * a + m * pt[i - 2] >= b){
                b -= pt[i - 2] * a + pt[i - 2];
                r[1] = a;
                for(j = 2; j <= i; j++){
                    x = pt[ max(0, i - j - 1) ];
                    r[j] = min(m, 1 + b / x);
                    b -= x * (r[j] - 1);
                    for(ii = j - 1; ii >= 1; ii--){
                        r[j] += r[ii];
                    }
                }
                cout<< i <<" ";
                for(j = 1; j <= i; j++){
                    cout<< r[j] <<" ";
                }
                cout<<"\n";
                break;
            }
            if(pt[i - 2] * a + pt[i - 2] > b){
                i = 51;
                break;
            }
        }
        if(i == 51){
            cout<<"-1\n";
        }
    }
}