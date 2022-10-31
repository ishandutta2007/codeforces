#include<iostream>
#define f first
#define s second
using namespace std;
int nr1, nr2, ok1, ok2, i, j, minim, n, m;
int a[105][105], b1[105][105], b2[105][105];
pair<int, int> v1[500005], v2[500005];
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin>> a[i][j];
        }
    }
    minim = 1000;
    for(i = 1; i <= m; i++){
        minim = min(minim, a[1][i]);
    }
    for(i = 1; i <= minim; i++){
        v1[++nr1] = make_pair(0, 1);
    }
    for(i = 1; i <= m; i++){
        b1[1][i] = minim;
        while(b1[1][i] < a[1][i]){
            v1[++nr1] = make_pair(1, i);
            for(j = 1; j <= n; j++){
                b1[j][i]++;
            }
        }
    }
    for(i = 2; i <= n; i++){
        if(a[i][1] < b1[i][1]){
            ok1 = 1;
        }
        for(j = 2; j <= m; j++){
            if(a[i][j] < b1[i][j] || a[i][j] - b1[i][j] != a[i][j - 1] - b1[i][j - 1]){
                ok1 = 1;
            }
        }
        if(ok1 == 1){
            continue;
        }
        while(a[i][1] != b1[i][1]){
            v1[++nr1] = make_pair(0, i);
            b1[i][1]++;
        }
    }

    minim = 1000;
    for(i = 1; i <= n; i++){
        minim = min(minim, a[i][1]);
    }
    for(i = 1; i <= minim; i++){
        v2[++nr2] = make_pair(1, 1);
    }
    for(i = 1; i <= n; i++){
        b2[i][1] = minim;
        while(b2[i][1] < a[i][1]){
            v2[++nr2] = make_pair(0, i);
            for(j = 1; j <= m; j++){
                b2[i][j]++;
            }
        }
    }
    for(i = 2; i <= m; i++){
        if(a[1][i] < b2[1][i]){
            ok2 = 1;
        }
        for(j = 2; j <= n; j++){
            if(a[j][i] < b2[j][i] || a[j][i] - b2[j][i] != a[j - 1][i] - b2[j - 1][i]){
                ok2 = 1;
            }
        }
        if(ok2 == 1){
            continue;
        }
        while(a[1][i] != b2[1][i]){
            v2[++nr2] = make_pair(1, i);
            b2[1][i]++;
        }
    }
    if(ok1 == 1 && ok2 == 1){
        cout<< -1;
    }
    else{
        if(ok2 == 1 || nr1 < nr2){
            cout<< nr1 <<"\n";
            for(i = 1; i <= nr1; i++){
                if(v1[i].f == 0){
                    cout<<"row ";
                }
                else{
                    cout<<"col ";
                }
                cout<< v1[i].s <<"\n";
            }
        }
        else{
             cout<< nr2 <<"\n";
            for(i = 1; i <= nr2; i++){
                if(v2[i].f == 0){
                    cout<<"row ";
                }
                else{
                    cout<<"col ";
                }
                cout<< v2[i].s <<"\n";
            }
        }
    }
    return 0;
}