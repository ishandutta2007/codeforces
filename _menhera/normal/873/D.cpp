//VS Support

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <cstdlib>
#include <cstdarg>

#define NORETURN void

//myassert Function. 
void myassert(bool p, const char *msg = "Error Occured!", ...)
{
    if(!p)
    {
        va_list args;
        va_start(args, msg);
        vfprintf(stderr, msg, args);
        fprintf(stderr, "\n");
        va_end(args);
        exit(0);
    }
}

//scan-related Function

#define scanInt(x, a, b) _scanInt(x, #x, a, b)
#define scanLL(x, a, b) _scanLL(x, #x, a, b)
void _scanInt(int& N, const char* vN, int a, int b)
{
    myassert(1 == scanf("%d", &N), "Error Occured!: Cannot read %s", vN);
    myassert(a <= N && N <= b, "Error Occured!: %s should be in [%d, %d]", vN, a, b); 
}

void _scanLL(long long& N, const char* vN, long long a, long long b)
{
    myassert(1 == scanf("%lld", &N), "Error Occured!: Cannot read %s", vN);
    myassert(a <= N && N <= b, "Error Occured!: %s should be in [%lld, %lld]", vN, a, b); 
}

// PROBLEM HEADER

void solve(int N, int K, int arr[], int v)
{
    if(K==1)
    {
        for(int i=0; i<N; ++i)
            arr[i] = v + i;
        return;
    }
    int l = K/2; if(l%2==0) l--;
    int r = K/2; if(r%2==0) r++;
    
    solve(N/2, l, arr, v+(N-N/2));
    solve(N-N/2, r, arr+N/2, v);
}

bool specialSequence(int N, int K, int arr[])
{
    if(K%2==0) return false;
    if(K>2*N-1) return false;
    solve(N, K, arr, 1);
    return true;
}

// MAIN STARTS HERE

int main()
{
    int N; int K;
    scanInt(N, 1, 100000);
    scanInt(K, 1, 200000);
    int *arr = new int[N];
    
    bool res = specialSequence(N, K, arr);
    
    if(res)
    {
        for(int i=0; i<N; ++i)
        {
            printf("%d", arr[i]);
            if(i == N-1) printf("\n");
            else printf(" ");
        }
    }
    else
    {
        puts("-1");
    }
    
    delete[] arr;
    
    return 0;
}