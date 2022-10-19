#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a, b;
int x, y, X = 5;
int A = 10, B = 10;
int f (int c, int d){
    if ((A ^ c) > (B ^ d))
        return 1;
    if ((A ^ c) < (B ^ d))
        return -1;
    return 0;
}

int main()
{
    int c, d;
    for (int i = 29; i >= 0; i--){
        x = X;
        if (x == 5){
            c = a;
            d = b;
            x = f (c, d);
            cout<<"? "<<c<<" "<<d<<endl;fflush(stdout);
            cin>>x;
        }
        X = 5;
        if (x == 0){
            for (int j = i; j >= 0; j--){
                c = (a ^ (1<<j));
                d = b;
                x = f (c, d);
                cout<<"? "<<c<<" "<<d<<endl;fflush(stdout);
                cin>>x;
                if (x == -1){
                    a ^= (1<<j);
                    b ^= (1<<j);
                }
            }
            cout<<"! "<<a<<" "<<b<<endl;fflush(stdout);
            return 0;
        }
        c = (a ^ (1<<i));
        d = (b ^ (1<<i));
        y = f (c, d);
        cout<<"? "<<c<<" "<<d<<endl;fflush(stdout);
        cin>>y;
        if (x != y){
            if (x == 1)
                a ^= (1<<i);
            else
                b ^= (1<<i);
            continue;
        }
        X = x;
        if (x == 1){
            c = (a ^ (1<<i));
            d = b;
            y = f (c, d);
            cout<<"? "<<c<<" "<<d<<endl;fflush(stdout);
            cin>>y;
            if (y == -1){
                a ^= (1<<i);
                b ^= (1<<i);
            }
            continue;
        }
        else {
            c = a;
            d = (b ^ (1<<i));
            y = f (c, d);
            cout<<"? "<<c<<" "<<d<<endl;fflush(stdout);
            cin>>y;
            if (y == 1){
                a ^= (1<<i);
                b ^= (1<<i);
            }
            continue;
        }
    }
    cout<<"! "<<a<<" "<<b<<endl;
    return 0;
}