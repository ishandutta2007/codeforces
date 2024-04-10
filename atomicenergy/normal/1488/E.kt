fun readInt():Int{return readLine()!!.toInt()}
fun readInts():List<Int>{return readLine()!!.split(" ").map{i -> i.toInt()}.toMutableList()}
fun readLong():Long{return readLine()!!.toLong()}
fun readLongs():List<Long>{return readLine()!!.split(" ").map{i -> i.toLong()}.toMutableList()}

var l = mutableListOf(0, 0);
var r = mutableListOf(0, 1);
var mxs = mutableListOf(0, 0);

fun set(a:Int, b:Int, c:Int){
    
    mxs[c] = maxOf(mxs[c], b);
    if(l[c] == r[c]) return;
    if(l[c*2] <= a && a <= r[c*2]) set(a, b, c*2);
    if(l[c*2+1] <= a && a <= r[c*2+1]) set(a, b, c*2+1);
}

fun query(a: Int, b:Int, c:Int):Int{
    if(l[c] > b) return 0;
    if(r[c] < a) return 0;
    if(l[c] > r[c]) return 0;
    if(a <= l[c] && b >= r[c]) return mxs[c];
    return maxOf(query(a, b, c*2), query(a, b, c*2+1));
}


fun main(args: Array<String>) {
    var t = readLong();
    for(q in 0..t-1){
        var n = readInt();
        var v = readInts();
        var m = List(n+1){-1}.toMutableList();
         l = mutableListOf(0, 0);
         r = mutableListOf(0, n-1);
         mxs = mutableListOf(0, 0);
         var z = 1;
         while(z < n) z*=2;
        for(i in 1..z){
            l.add(l[i])
            r.add((l[i] + r[i])/2)
            l.add((l[i] + r[i])/2 + 1)
            r.add(r[i])
            mxs.add(0)
            mxs.add(0)
        }
        var ans = 0;
        for(i in 0..n-1){
            if(m[v[i]] != -1){
                var f:Int = m[v[i]];
                var cur = query(f+1, i, 1);
                ans = maxOf(ans, cur+2);
                set(f, cur+2, 1);
                set(i, 1, 1);
                
            }else{
                m[v[i]] = i;
                //set i to 1
                set(i, 1, 1);
                ans = maxOf(ans, 1);
            }
        }
        println(ans);
    }
}