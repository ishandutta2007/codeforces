fun readInt():Int{return readLine()!!.toInt()}
fun readInts():List<Int>{return readLine()!!.split(" ").map{i -> i.toInt()}.toMutableList()}
fun readLong():Long{return readLine()!!.toLong()}
fun readLongs():List<Long>{return readLine()!!.split(" ").map{i -> i.toLong()}.toMutableList()}

fun main(args: Array<String>) {
    var n = readLong();
    for(i in 0..n-1){
        var (x, y) = readLongs();
        var k:Long = 0;
        var tot:Long = 0;
        var z:Long = 1000000000
        for(j in 0..9){
            while(k + x*z <= y){
                k += x*z;
                tot++;
            }
            z/=10;
            //println(z);
        }
        tot += y-k;
        println(tot);
    }
}