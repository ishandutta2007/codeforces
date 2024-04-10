#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
set < pair < int, int > > b;
set < pair < int, int > > a;

int abs(int a){
    if (a > 0)
        return a;
    else
        return -a;
}

int main()
{
    int suma = 0, sumb = 0, i, n, x, top = 0;
    cin >> n;
    for (i = 0; i < n; i++){
        scanf("%d", &x);
        if (i < n / 2){
            a.insert(make_pair(x, i));
            suma += x;
        }
        else{
            b.insert(make_pair(x, i));
            sumb += x;
        }
        top = max(top, x);
    }
    set < pair < int, int > > :: iterator k;
    while (abs(suma - sumb) > top){
        if (suma > sumb){
            k = a.end();
            k--;
            b.insert(*k);
            sumb += k->first;
            suma -= k->first;
            a.erase(k);
            suma += b.begin()->first;
            sumb -= b.begin()->first;
            a.insert(*(b.begin()));
            b.erase(b.begin());
        }
        else{
            k = b.end();
            k--;
            a.insert(*k);
            suma += k->first;
            sumb -= k->first;
            cerr << b.size();
            b.erase(k);
            cerr << b.size();
            sumb += b.begin()->first;
            suma -= b.begin()->first;
            b.insert(*(a.begin()));
            a.erase(a.begin());
        }
    }
    cout << n / 2 << endl;
    while (! a.empty()){
        cout << a.begin()->second + 1 << " ";
        a.erase(a.begin());
    }
    cout << endl << n - n / 2 << endl;
    for (k = b.begin(); k != b.end(); k++)
        cout << k->second + 1 << " ";

    return 0;
}