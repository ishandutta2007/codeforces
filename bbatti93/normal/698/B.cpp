#include <bits/stdc++.h>

using namespace std;

int n, ki, t[200001], boss=-1, volt[200001];

void beallit(int a) {
    if(boss==-1) boss=a;
    if(t[a]!=boss) ki++;
    t[a]=boss;
}

void bejar(int a) {
    volt[a]=1;
    if(volt[t[a]]==1) beallit(a);
    else if(volt[t[a]]==0) bejar(t[a]);
    volt[a]=2;
}


int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> t[i];
        t[i]--;
    }
    for(int i=0;i<n;i++) {
        if(t[i]==i && boss==-1) boss=i;
    }
    for(int i=0;i<n;i++) {
        if(!volt[i]) bejar(i);
    }
    cout << ki <<endl;
    for(int i=0;i<n;i++) cout << t[i]+1 << " ";
    cout << endl;
    return 0;
}