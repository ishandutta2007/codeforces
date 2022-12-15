#include <stdio.h>
#include <utility>

typedef std::pair<int, int> iPair;

int n, a, b, k;
char str[200100];

int size = 0;
iPair arr[200100];

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d %d %d %d", &n, &a, &b, &k);
    scanf("%s", str);

    int prev = -1; 
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '1') {
            arr[size].first = (i - prev - 1) / b;
            arr[size].second = prev;
            sum += arr[size].first;
            size++;
            prev = i;
        }
    }
    if(str[n - 1] == '0') {
        arr[size].first = (n - prev - 1) / b;
        arr[size].second = prev;
        sum += arr[size].first;
        size++;
        prev = n;
    }
    printf("%d\n", sum - a + 1);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < arr[i].first && sum >= a; j++) {
            sum--;
            printf("%d ", arr[i].second + b + 1);
            arr[i].second += b;
        }
        if(sum < a) break;
    }

    return 0;
}