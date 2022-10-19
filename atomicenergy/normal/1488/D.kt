fun readInt():Int{return readLine()!!.toInt()}
fun readInts():List<Int>{return readLine()!!.split(" ").map{i -> i.toInt()}.toMutableList()}
fun readLong():Long{return readLine()!!.toLong()}
fun readLongs():List<Long>{return readLine()!!.split(" ").map{i -> i.toLong()}.toMutableList()}

fun main(args: Array<String>) {
    var t = readLong();
    for(q in 0..t-1){
        var (n, s) = readLongs();
        var lo : Long = 1
        var hi : Long = s+1
        while(hi - lo > 1){
            var md : Long = (lo + hi)/2;
            var tot : Long = 0;
            var cur : Long = md;
            for(i in 0..n-1){
                tot += cur;
                cur = (cur + 1)/2;
                if(cur == 1L){
                    tot += n-1-i;
                    break;
                }
            }
            if(tot > s){
                hi = md;
            }else{
                lo = md;
            }
        }
        println(lo)
    }
}