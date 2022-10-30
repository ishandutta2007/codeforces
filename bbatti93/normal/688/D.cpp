#include<bits/stdc++.h>

using namespace std;
bool p[1000010];
vector< vector<int> > primhatvanyok;
int szam;

vector<int> primfelbontas;
vector<bool> kesze;
int maxom=1000000;
int n,k;

bool lehet=true;

int main () {
    for (int i=2; i<=maxom; i++) {
        if (p[i]==false) {
            primhatvanyok.push_back(vector<int>());
            szam++;
            int j=2*i;
            while (j<=maxom) {
                p[j]=true;
                j+=i;
            }
            j=i;
            while (j<=maxom) {
                primhatvanyok[szam-1].push_back(j);
                j*=i;
            }
        }
    }
    cin>>n>>k;

    for (int i=0; i<primhatvanyok.size(); i++) {
        if ( k % primhatvanyok[i][0] == 0) {
            int tart=0;
            while (tart<primhatvanyok[i].size() && (k % primhatvanyok[i][tart] == 0)) tart++;
            primfelbontas.push_back(primhatvanyok[i][tart-1]);
            kesze.push_back(false);
        }
    }

    for (int i=1; i<=n; i++) {
        int a;
        scanf("%d",&a);
        for (int i=0; i<primfelbontas.size(); i++) {
            if (a % primfelbontas[i] == 0) kesze[i]=true;
        }
    }

    for (int i=0; i<kesze.size(); i++) {
        if (kesze[i]==false) lehet=false;
    }
    if (lehet==false) cout<<"No";
    else cout<<"Yes";



}