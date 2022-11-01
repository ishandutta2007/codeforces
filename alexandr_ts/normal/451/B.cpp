#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;

int a[1000000];
int b[1000000];


template <class ForwardIterator>
  bool is_sorted (ForwardIterator first, ForwardIterator last)
{
  if (first==last) return true;
  ForwardIterator next = first;
  while (++next!=last) {
    if (*next<*first)     // or, if (comp(*next,*first)) for version (2)
      return false;
    ++first;
  }
  return true;
}

main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    a[n + 1] = 2000000000;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int c1 = 1, c2 = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] > a[i + 1])
    {
        c1 = i;
        break;
    }
    for (int i = c1; i <= n; i++)
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
    {
        c2 = i;
        break;
    }
    //cout << c1 << " " << c2 << endl;
    reverse(a + c1, a + c2 + 1);
    //for (int i = 0; i< n + 1; i++)
        //cout << a[i] << " ";cout << endl;
    if (is_sorted(a + 1, a + n + 1))
    {
        cout << "yes " << c1 << " " << c2;
    }
    else
        cout << "no";


}