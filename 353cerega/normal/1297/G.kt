fun cont(len: Int, cnt: Array<Int>): Long
{
    var L = len
    var ans: Long = 1
    cnt.sort()
    for (i in 0..8)
    {
        if (cnt[i]>60) return 2000000000
        for (j in 0..(cnt[i]-1))
        {
            ans *= L
            L--
            ans /= (j+1)
            if (ans>1000000000) return 1000000001
        }
    }
    return ans
}


fun calc(len: Int, kek: Array<Int>): Long
{
    var sum: Long = 0
    if (len<kek[2]/3 + kek[3]/2 + kek[5] + kek[7]) return 0
    var k = 0
    while (2*k<=kek[2] && k+kek[5]+kek[7]<=len)
    {
        var l = 0
        while (2*l<=kek[3] && l+k+kek[5]+kek[7]<=len)
        {
            var m = 0
            while (2*k+3*m<=kek[2] && m+l+k+kek[5]+kek[7]<=len)
            {
                var n = 0
                while (2*k+3*m+n<=kek[2] && 2*l+n<=kek[3])
                {
                    if (m+l+k+kek[5]+kek[7]+kek[2]-2*k-3*m+kek[3]-2*l-n>len)
                    {
                        n = m+l+k+kek[5]+kek[7]+kek[2]-2*k-3*m+kek[3]-2*l-n-len
                        continue
                    }
                    var cnt = Array<Int>(10,{0})
                    for (pos in 2..9)
                    {
                        cnt[pos] = kek[pos]
                    }
                    cnt[2] -= 2*k+3*m+n
                    cnt[3] -= 2*l+n
                    cnt[4] = k
                    cnt[6] = n
                    cnt[8] = m
                    cnt[9] = l
                    cnt[1] = len-cnt[2]-cnt[3]-cnt[4]-cnt[5]-cnt[6]-cnt[7]-cnt[8]-cnt[9]
                    sum += cont(len,cnt)
                    if (sum>1000000000)
                    {
                        return sum
                    }
                    n++
                }
                m++
            }
            l++
        }
        k++
    }
    return sum
}


fun main(args: Array<String>) = with(java.util.Scanner(System.`in`))
{
    //var n = nextInt()
    //var map: MutableMap<Int, Int>
    //var numbers: Array<Array<Int>> = Array(3, { Array(5, {0}) })
    //var numbers3: MutableSet<Int> = sortedSetOf(15, 16, 17)
    //var t = nextInt()
    var t = 1
    for (q in 1..t)
    {
        var m = nextInt()
        var k: Long = nextLong()
        var step = Array(10,{0})
        for (i in 2..9)
        {
            while (m%i==0)
            {
                step[i]++
                m/=i
            }
        }

        if (m!=1)
        {
            println(-1)
            continue
        }
        k--
        for (len in 1..1000000)
        {
            var a = calc(len,step)
            if (a<=k)
            {
                k = k-a
                continue
            }
            var ans = Array(len,{0})
            var pos = 0
            while (pos<len)
            {
                var tmp = calc(len-pos-1,step)
                if (tmp<=k)
                {
                    k -= tmp
                }
                else
                {
                    ans[pos] = 1
                    pos++
                    continue
                }
                if (step[2]>=1)
                {
                    step[2]--
                    tmp = calc(len-pos-1,step)
                    if (tmp<=k)
                    {
                        k -= tmp
                    }
                    else
                    {
                        ans[pos] = 2
                        pos++
                        continue
                    }
                    step[2]++
                }
                if (step[3]>=1)
                {
                    step[3]--
                    tmp = calc(len-pos-1,step)
                    if (tmp<=k)
                    {
                        k -= tmp
                    }
                    else
                    {
                        ans[pos] = 3
                        pos++
                        continue
                    }
                    step[3]++
                }
                if (step[2]>=2)
                {
                    step[2]-=2
                    tmp = calc(len-pos-1,step)
                    if (tmp<=k)
                    {
                        k -= tmp
                    }
                    else
                    {
                        ans[pos] = 4
                        pos++
                        continue
                    }
                    step[2]+=2
                }
                if (step[5]>=1)
                {
                    step[5]--
                    tmp = calc(len-pos-1,step)
                    if (tmp<=k)
                    {
                        k -= tmp
                    }
                    else
                    {
                        ans[pos] = 5
                        pos++
                        continue
                    }
                    step[5]++
                }
                if (step[2]>=1 && step[3]>=1)
                {
                    step[2]--
                    step[3]--
                    tmp = calc(len-pos-1,step)
                    if (tmp<=k)
                    {
                        k -= tmp
                    }
                    else
                    {
                        ans[pos] = 6
                        pos++
                        continue
                    }
                    step[2]++
                    step[3]++
                }
                if (step[7]>=1)
                {
                    step[7]--
                    tmp = calc(len-pos-1,step)
                    if (tmp<=k)
                    {
                        k -= tmp
                    }
                    else
                    {
                        ans[pos] = 7
                        pos++
                        continue
                    }
                    step[7]++
                }
                if (step[2]>=3)
                {
                    step[2]-=3
                    tmp = calc(len-pos-1,step)
                    if (tmp<=k)
                    {
                        k -= tmp
                    }
                    else
                    {
                        ans[pos] = 8
                        pos++
                        continue
                    }
                    step[2]+=3
                }
                ans[pos] = 9
                step[3]-=2
                pos++
            }
            for (i in 0..(len-1))
            {
                print(ans[i])
            }
            return
        }
    }

}