#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

char s[262144];
int lc[524287], lx[524287], cl[524287], cr[524287], rj[524287], rx[524287], sol[524287];

void build_tree(int l, int r)
{
    if (l == r)
    {
        if (s[l] == '(')
        {
            lc[l + r] = 1;
            lx[l + r] = 1;
            cl[l + r] = 1;
            cr[l + r] = 0;
            rj[l + r] = 0;
            rx[l + r] = 1;
            sol[l + r] = 0;
        }
        else if (s[r] == ')')
        {
            lc[l + r] = 0;
            lx[l + r] = 1;
            cl[l + r] = 0;
            cr[l + r] = 1;
            rj[l + r] = 1;
            rx[l + r] = 1;
            sol[l + r] = 0;
        }
        else
        {
            lc[l + r] = 0;
            lx[l + r] = 0;
            cl[l + r] = 0;
            cr[l + r] = 0;
            rj[l + r] = 0;
            rx[l + r] = 0;
            sol[l + r] = 0;
        }
        return;
    }
    
    build_tree(l, (l + r) / 2);
    build_tree((l + r + 1) / 2, r);
    int L = l + (l + r) / 2;
    int R = (l + r + 1) / 2 + r;

    if (cl[L] > cr[R])
    {
        cr[l + r] = cr[L];
        cl[l + r] = cl[R] + cl[L] - cr[R];
    }
    else
    {
        cr[l + r] = cr[L] + cr[R] - cl[L];
        cl[l + r] = cl[R];
    }

    lx[l+r] = std::max(lx[L], std::max(
                cr[L] + cl[L] + lc[R],
                cr[L] - cl[L] + lx[R]
                ));
    rx[l+r] = std::max(rx[R], std::max(
                cl[R] + cr[R] + rj[L],
                cl[R] - cr[R] + rx[L]
                ));

    lc[l+r] = std::max(lc[L],
            -cr[L] + cl[L] + lc[R]);
    rj[l+r] = std::max(rj[R],
            -cl[R] + cr[R] + rj[L]);

    sol[l + r] = std::max(sol[L], sol[R]);
    sol[l + r] = std::max(sol[l + r], cl[l + r] + cr[l + r]);
    sol[l + r] = std::max(sol[l + r], rj[L] + lx[R]);
    sol[l + r] = std::max(sol[l + r], rx[L] + lc[R]);

    /*
    if (r < 8)
    {
        cerr << l << " " << r << " " << cl[l + r] << " " << cr[l + r] << " " 
            << lc[l+r] << " " << rj[l+r] << " " << sol[l + r] << endl;
    }
    */
}

void update(int l, int r, int x)
{
    if (l == r)
    {
        if (s[l] == '(')
        {
            lc[l + r] = 1;
            lx[l + r] = 1;
            cl[l + r] = 1;
            cr[l + r] = 0;
            rj[l + r] = 0;
            rx[l + r] = 1;
            sol[l + r] = 0;
        }
        else if (s[r] == ')')
        {
            lc[l + r] = 0;
            lx[l + r] = 1;
            cl[l + r] = 0;
            cr[l + r] = 1;
            rj[l + r] = 1;
            rx[l + r] = 1;
            sol[l + r] = 0;
        }
        else
        {
            lc[l + r] = 0;
            lx[l + r] = 0;
            cl[l + r] = 0;
            cr[l + r] = 0;
            rj[l + r] = 0;
            rx[l + r] = 0;
            sol[l + r] = 0;
        }
        return;
    }
    
    if (x <= (l + r) / 2)
    {
        update(l, (l + r) / 2, x);
    }
    else
    {
        update((l + r + 1) / 2, r, x);
    }
    int L = l + (l + r) / 2;
    int R = (l + r + 1) / 2 + r;

    if (cl[L] > cr[R])
    {
        cr[l + r] = cr[L];
        cl[l + r] = cl[R] + cl[L] - cr[R];
    }
    else
    {
        cr[l + r] = cr[L] + cr[R] - cl[L];
        cl[l + r] = cl[R];
    }

    lx[l+r] = std::max(lx[L], std::max(
                cr[L] + cl[L] + lc[R],
                cr[L] - cl[L] + lx[R]
                ));
    rx[l+r] = std::max(rx[R], std::max(
                cl[R] + cr[R] + rj[L],
                cl[R] - cr[R] + rx[L]
                ));

    lc[l+r] = std::max(lc[L],
            -cr[L] + cl[L] + lc[R]);
    rj[l+r] = std::max(rj[R],
            -cl[R] + cr[R] + rj[L]);

    sol[l + r] = std::max(sol[L], sol[R]);
    sol[l + r] = std::max(sol[l + r], cl[l + r] + cr[l + r]);
    sol[l + r] = std::max(sol[l + r], rj[L] + lx[R]);
    sol[l + r] = std::max(sol[l + r], rx[L] + lc[R]);
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    memset(s, 0, sizeof(s));
    cin >> s;

    build_tree(0, 262143);
    cout << sol[262143] << endl;

    for (int i = 0; i < q; ++i)
    {
        int a, b;
        cin>>a>>b;
        --a;--b;
        s[a] ^= '(' ^ ')';
        update(0, 262143, a);
        s[b] ^= '(' ^ ')';
        update(0, 262143, b);
        cout << sol[262143] << endl;
    }

    return 0;
}