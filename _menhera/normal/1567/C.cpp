#include <bits/stdc++.h>
using namespace std;

int count(int num, int carry)
{
    if(num == 0) return carry == 0 ? 1 : 0;

    int last_digit = num%10, last_carry = carry%10;

    int sum_with_carry = last_digit + 10 - last_carry;
    int cases_carry = 10 - abs(9 - sum_with_carry);

    int sum_without_carry = last_digit - last_carry;
    int cases_no_carry = 10 - abs(9 - sum_without_carry);

    return cases_carry * count(num/10, carry/10 + 10) + cases_no_carry * count(num/10, carry/10);
}

int solve(int N)
{
    return count(N, 0) - 2;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        cout << solve(N) << endl;
    }
}