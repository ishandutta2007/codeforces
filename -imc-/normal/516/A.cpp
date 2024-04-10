#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> digits;
    
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf(" %c", &c);
        
        int digit = c - '0';
        
        if (digit == 0 || digit == 1) continue;
        if (digit == 2 || digit == 3 || digit == 5 || digit == 7) digits.push_back(digit);
        if (digit == 4)
        {
            digits.push_back(3);
            digits.push_back(2);
            digits.push_back(2);
        }
        if (digit == 6)
        {
            digits.push_back(5);
            digits.push_back(3);
        }
        if (digit == 8)
        {
            digits.push_back(7);
            digits.push_back(2);
            digits.push_back(2);
            digits.push_back(2);
        }
        if (digit == 9)
        {
            digits.push_back(7);
            digits.push_back(3);
            digits.push_back(3);
            digits.push_back(2);
        }
    }
    
    sort(digits.begin(), digits.end());
    for (int i = digits.size() - 1; i >= 0; i--)
        printf("%d", digits[i]);
    printf("\n");
    
    return 0;
}