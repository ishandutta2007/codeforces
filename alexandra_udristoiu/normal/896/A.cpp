#include<iostream>
#include<cstring>
#define INF 1e18
using namespace std;
int n, q, i;
long long k, num[100005];
char sol[100005];
char f0[] = " What are you doing at the end of the world? Are you busy? Will you save us?";
char p1[] = " What are you doing while sending ";
char p2[] = " ? Are you busy? Will you send ";
char solve(int n, long long k){
    if(n == 0){
        if(k == 1 || k == strlen(f0 + 1) + 2){
            return '"';
        }
        else{
            return f0[k - 1];
        }
    }
    if(k == 1){
        return '"';
    }
    k--;
    if(k <= strlen(p1 + 1)){
        return p1[k];
    }
    k -= strlen(p1 + 1);
    if(k <= num[n - 1] + 2){
        return solve(n - 1, k);
    }
    k -= num[n - 1] + 2;
    if(k <= strlen(p2 + 1)){
        return p2[k];
    }
    k -= strlen(p2 + 1);
    if(k <= num[n - 1] + 2){
        return solve(n - 1, k);
    }
    k -= num[n - 1] + 2;
    if(k == 1){
        return '?';
    }
    else{
        return '"';
    }
}
int main(){
    num[0] = strlen(f0 + 1);
    for(i = 1; i <= 100000; i++){
        num[i] = strlen(p1 + 1) + strlen(p2 + 1) + 2 * num[i - 1] + 5;
        if(num[i] > INF){
            num[i] = INF + 1;
        }
    }
    cin>> q;
    for(i = 1; i <= q; i++){
        cin>> n >> k;
        if(num[n] < k){
            sol[i] = '.';
            continue;
        }
        if(k == 1){
            sol[i] = p1[1];
            continue;
        }
        if(n == 0){
            sol[i] = f0[k];
        }
        else{
            k++;
            sol[i] = solve(n, k);
        }
    }
    cout<< sol + 1;
}