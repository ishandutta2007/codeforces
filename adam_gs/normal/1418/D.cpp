#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
set<int>S;
priority_queue<pair<int,pair<int,int>>>kol;
int akt;
void dodaj(int a) {
    ++akt;
    S.insert(a);
    auto it=S.find(a);
    if(it!=S.begin()) {
        auto tmp=it; --tmp;
        int a=*tmp, b=*it;
        kol.push({b-a-1, {a, b}});
    }
    auto tmp=it; ++tmp;
    if(tmp!=S.end()) {
        int a=*it, b=*tmp;
        kol.push({b-a-1, {a, b}});
    }
}
void usun(int a) {
    --akt;
    auto it=S.find(a), p=it, k=it;
    if(p!=S.begin()) {
        --p; ++k;
        if(k!=S.end()) {
            int a=*p, b=*k;
            kol.push({b-a-1, {a, b}});
        }
    }
    S.erase(a);
}
void wypisz() {
    if(akt<=2) {
        cout << "0\n";
        return;
    }
    while(!kol.empty()) {
        int a=kol.top().nd.st, b=kol.top().nd.nd;
        auto it1=S.find(a), it2=S.find(b), it3=it1; ++it3;
        if(it1==S.end() || it2==S.end() || it2!=it3) kol.pop();
        else break;
    }
    auto p=S.begin(), k=S.end(); --k;
    int a=*p, b=*k;
    cout << b-a-1-kol.top().st << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    while(n--) {
        int a;
        cin >> a;
        dodaj(a);
    }
    wypisz();
    while(q--) {
        int x, a;
        cin >> x >> a;
        if(x) dodaj(a);
        else usun(a);
        wypisz();
    }
}