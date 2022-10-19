fun readInt():Int{return readLine()!!.toInt()}
fun readInts():List<Int>{return readLine()!!.split(" ").map{i -> i.toInt()}.toMutableList()}
fun readLong():Long{return readLine()!!.toLong()}
fun readLongs():List<Long>{return readLine()!!.split(" ").map{i -> i.toLong()}.toMutableList()}

fun main(args: Array<String>) {
    var n = readLong();
    for(i in 0..n-1){
        var (a, k) = readInts();
        var s = readLine()!!
        var cur = 0;
        var first = 0;
        var second = 0;
        for(j in 0..s.length-1){
            if(s[j] == '('){
                if(cur == 0) first++;
                else second++;
                cur++;
            }
            if(s[j] == ')'){
                cur--;
            }
        }
        println(first + minOf(second, k));
    }
}