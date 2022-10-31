#include<iostream>
using namespace std;
int n, i, p, u, px, py, j, nr, st;
char s[2005], s2[2005], aux[2005];
int ff[30], ff2[30], sol[6005];
int ind(int p, int x){
    if(p <= x){
        return p + n - x;
    }
    else{
        return n - p + 1;
    }
}
void op(int x){
    sol[++nr] = n - x;
    int i;
    for(i = 1; i <= x; i++){
        aux[i + n - x] = s[i];
    }
    for(i = x + 1; i <= n; i++){
        aux[n - i + 1] = s[i];
    }
    for(i = 1; i <= n; i++){
        s[i] = aux[i];
    }
    p = ind(p, x);
    u = ind(u, x);
    px = ind(px, x);
    py = ind(py, x);
}
int main(){
    cin>> n;
    cin>> s + 1;
    cin>> s2 + 1;
    for(i = 1; i <= n; i++){
        ff[ s[i] - 'a']++;
        ff2[ s2[i] - 'a' ]++;
    }
    for(i = 0; i < 26; i++){
        if(ff[i] != ff2[i]){
            cout<< -1;
            return 0;
        }
    }
    if(n % 2 == 1){
        for(i = 1; i <= n; i++){
            if(s[i] == s2[1]){
                op(i);
                break;
            }
        }
        st = 2;
    }
    else{
        st = 3;
        for(j = 1; j <= n; j++){
            if(px == 0 && s2[1] == s[j]){
                px = j;
            }
            else{
                if(py == 0 && s2[2] == s[j]){
                    py = j;
                }
            }
        }
        op(px);
        op(n - 1);
        op(py - 1);
        op(px);
        op(py - 1);
        op(py);
    }
    for(i = st; i < n; i += 2){
        px = py = 0;
        p = n - i + 2;
        u = n;
        for(j = 1; j <= n; j++){
            if(px == 0 && s2[i] == s[j]){
                px = j;
            }
            else{
                if(py == 0 && s2[i + 1] == s[j]){
                    py = j;
                }
            }
        }
        op(px);
        op(n - 1);
        op(py - 1);
        op(p);
        op(py - 1);
        op(py);
    }
    cout<< nr <<"\n";
    for(i = 1; i <= nr; i++){
        cout<< sol[i] <<" ";
    }
}