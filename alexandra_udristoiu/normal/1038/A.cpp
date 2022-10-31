#include<iostream>
using namespace std;
int n, i, k, minim;
int ff[30];
char s[100005];
int main(){
    cin>> n >> k;
    cin>> s;
    for(i = 0; i < n; i++){
        ff[ s[i] - 'A' ]++;
    }
    minim = n;
    for(i = 0; i < k; i++){
        minim = min(minim, ff[i]);
    }
    cout<< minim * k;
}