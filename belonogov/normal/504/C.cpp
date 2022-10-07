#include <bits/stdc++.h>

using namespace std;

#define left sdfadf
#define right asdf

const int N = 1e6 + 10;
map < int, int > bal;
long long ans;
int b[N], a[N];
int n, left, right, mxSuf, cntNeg;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void add(int x) {
    if (bal[-x] > 0) {
        bal[-x]--;
        cntNeg--;
    }
    else {
        bal[x]++;
    }
}

void erase(int x) {
    if (bal[x] > 0) {
        bal[x]--;
    }
    else {
        bal[-x]++;
        cntNeg++;
    }
}

int mirror(int x) {
    return n - x - 1;
}

void nextStep1() {
    if (left <= mirror(right)) {
        add(a[right]);
        add(a[right]);
    }
    else {
        add(a[right]);
        erase(a[mirror(right)]);
    }
    right++;
}

void nextStep2() {
    add(a[right]); 
    erase(a[mirror(right)]);
    right++;
}

void solve() {
    int lastLeft = n / 2;
    int firstRight = (n + 1) / 2; 
    for (int i = 0; i < n; i++)
        b[a[i]]++;
    int cntOdd = 0; 
    for (int i = 1; i <= n; i++)
        cntOdd += b[i] % 2;
    if (cntOdd != n % 2) {
        printf("0\n");
        exit(0);
    }

    mxSuf = 0;
    ans = 0;
    for (; mxSuf < lastLeft && a[mxSuf] == a[n - mxSuf - 1]; mxSuf++);
    cntNeg = 0;
    bal.clear();
    for (int i = 0; i < lastLeft + 1; i++)
        add(a[i]);
    for (int i = lastLeft + 1; i < n; i++) 
        erase(a[i]);

    right = lastLeft + 1; 
    for (left = 0; left < firstRight; left++) {
        while (right <= n) {
            int mnSuf = min(left, n - right);
            if (mnSuf > mxSuf || cntNeg > 0) {
                nextStep1();
                continue;
            }
            break;
        }
        ans += n - right + 1;
        if (left <= mirror(right))  {
            erase(a[left]);
            add(a[mirror(left)]);
        }
        else {
            erase(a[left]);
            erase(a[left]);
        }
    }
    int mxC = 0;
    for (; firstRight + mxC < n && a[firstRight + mxC] == a[mirror(firstRight + mxC)]; mxC++);
    int tmp = mirror(firstRight + mxC) + 1;
    long long ans2 = 0;
    bal.clear();
    cntNeg = 0;
    right = 0;
    for (left = 0; left <= mxSuf; left++) {
        while (right <= lastLeft) {
            if (right < tmp || cntNeg > 0 || left >= right) {
                nextStep2(); 
                continue;
            } 
            break;
        }            
        ans2 += lastLeft - right + 1;
        erase(a[left]);
        add(a[mirror(left)]);  
    }  
    ans += ans2 * 2;
}

int main(){
    read();
    solve();
    printf("%lld\n", ans);
    return 0;
}