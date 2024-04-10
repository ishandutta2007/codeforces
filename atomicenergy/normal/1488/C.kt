fun readInt():Int{return readLine()!!.toInt()}
fun readInts():List<Int>{return readLine()!!.split(" ").map{i -> i.toInt()}.toMutableList()}
fun readLong():Long{return readLine()!!.toLong()}
fun readLongs():List<Long>{return readLine()!!.split(" ").map{i -> i.toLong()}.toMutableList()}

fun main(args: Array<String>) {
    var t = readLong();
    for(q in 0..t-1){
        var (n, x, y) = readInts();
        if(x > y) {
            var t = x;
            x = y;
            y = t;
        }
        var mn = 2*n;
        for(i in x..y-1){
            mn = minOf(mn, maxOf(i-1 + minOf(x-1, i-x),  n-i-1 + minOf(y-i-1, n-y)))
        }
        println(mn)
    }
}