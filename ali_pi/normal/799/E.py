try:
    R1 = lambda: int(raw_input())
    R = lambda: map(int, raw_input().split())
    n, m, k = R()
    prices = R()
    R1()
    ais = set(R())
    R1()
    bis = set(R())

    noone_likes = []
    a_likes = []
    b_likes = []
    ab_likes = []


    for idx, price in enumerate(prices):
        in_ais = (idx+1) in ais
        in_bis = (idx+1) in bis
        if in_ais and in_bis:
            ab_likes.append(price)
        elif in_ais:
            a_likes.append(price)
        elif in_bis:
            b_likes.append(price)
        else:
            noone_likes.append(price)

    min_a_b_count = min(len(a_likes), len(b_likes))

    if m < k:
        print -1
        exit(0)

    if len(ab_likes) < k and len(ab_likes) + (k - len(ab_likes)) * 2 > m:
        print -1
        exit(0)

    if min_a_b_count + len(ab_likes) < k:
        print -1
        exit(0)


    for i in [a_likes, b_likes, ab_likes, noone_likes]:
        i.sort()


    import heapq
    free_heap = []


    if min_a_b_count > min(k, m - k):
        min_a_b_count = min(k, m - k)

    for i in [a_likes, b_likes]:
        for j in i[min_a_b_count:]:
            heapq.heappush(free_heap, j)

    a_likes = a_likes[:min_a_b_count]
    b_likes = b_likes[:min_a_b_count]

    for j in noone_likes:
        heapq.heappush(free_heap, j)

    # Only ab_likes
    if not a_likes:
        s = sum(ab_likes[:k])
        for i in ab_likes[k:]:
            heapq.heappush(free_heap, i)
        s += sum(heapq.heappop(free_heap) for _ in xrange(m - k))
        print s
        exit(0)

    # Minimal set of likes
    if len(a_likes) + len(ab_likes) == k:
        s = sum(ab_likes) + sum(a_likes) + sum(b_likes)
        s += sum(heapq.heappop(free_heap) for _ in xrange(m - (k + len(b_likes))))
        print s
        exit(0)

    # Sum with min number of ab_likes
    s = sum(ab_likes[:k - min_a_b_count]) + sum(a_likes) + sum(b_likes)
    count = k - min_a_b_count + (min_a_b_count * 2)

    extra_heap = []  # need to know max in extra values
    for _ in xrange(m - count):
        if not free_heap:  # if not too many ab_likes...
            break
        heapq.heappush(extra_heap, -1 * heapq.heappop(free_heap))
    s += -1 * sum(extra_heap)
    count += len(extra_heap)

    min_sum = s
    # Iterate on reminder of ab_likes
    for i in xrange(k - min_a_b_count, len(ab_likes)):
        if count == m:
            s += ab_likes[i] - a_likes[-1] - b_likes[-1]
            heapq.heappush(free_heap, a_likes.pop())
            heapq.heappush(free_heap, b_likes.pop())

            extra_item = heapq.heappop(free_heap)
            s += extra_item
            heapq.heappush(extra_heap, -1 * extra_item)

            # Make sure that newly added items are in extra_heap if they are cheaper
            free_min = heapq.heappop(free_heap)
            extra_min = -1 * heapq.heappop(extra_heap)
            if free_min < extra_min:
                s -= extra_min - free_min
                heapq.heappush(free_heap, extra_min)
                heapq.heappush(extra_heap, -1 * free_min)
            else:
                heapq.heappush(extra_heap, -1 * extra_min)
                heapq.heappush(free_heap, free_min)

            min_sum = min(min_sum, s)

            if not a_likes:
                for j in ab_likes[i+1:]:
                    if j < -1 * extra_heap[0]:
                        s -= -1 * extra_heap[0] - j
                        heapq.heappushpop(extra_heap, -1 * j)
                    else:
                        break
                min_sum = min(min_sum, s)
                break
        else:
            s += ab_likes[i]
            count += 1
            if count == m:
                min_sum = s

    print min_sum

except Exception, e:
    import sys
    print('L{}'.format(sys.exc_info()[-1].tb_lineno), type(e).__name__, len(ab_likes), len(a_likes), len(free_heap))