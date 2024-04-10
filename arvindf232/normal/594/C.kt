/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

class reading{
    companion object{
        var jin = BufferedReader(InputStreamReader(System.`in`))
        var pw = PrintWriter(System.out)
    }
}
fun put(aa:Any){
    reading.pw.println(aa)
}
fun done(){
    reading.pw.close()
}

fun getInt():Int{
    return reading.jin.readLine().toInt()
}
fun getLine():List<Int>{
    return reading.jin.readLine().split(" ").map { it.toInt() }
}
fun getLineL():List<Long>{
    return reading.jin.readLine().split(" ").map { it.toLong() }
}
fun getString():String{
    return reading.jin.readLine()
}


inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}
infix fun Long.divCeil(b:Long):Long{
    //Positives numbers only!
    if(this == 0L) {
        return 0
    }
    return (this-1)/b + 1
}


fun main() {
    val (n,k) = getLine()
    val xx = mutableListOf<Long>()
    val yy = mutableListOf<Long>()

    repeat(n){
        val (a,b,c,d) = getLineL()
        xx.add(a+c)
        yy.add(b+d)
    }
    val xSorted = xx.withIndex().sortedBy { it.value }
    val ySorted = yy.withIndex().sortedBy { it.value }


    val posMinX = xSorted.take(12).map{it.value}.toSet()
    val posMinY = ySorted.take(12).map{it.value}.toSet()
    val posMaxX = xSorted.takeLast(12).map{it.value}.toSet()
    val posMaxY = ySorted.takeLast(12).map{it.value}.toSet()

    val badPoints = mutableSetOf<Int>()

    badPoints.addAll(xSorted.take(12).map{it.index})
    badPoints.addAll(ySorted.take(12).map{it.index})
    badPoints.addAll(xSorted.takeLast(12).map{it.index})
    badPoints.addAll(ySorted.takeLast(12).map{it.index})

//    for(i in badPoints){
//        if(posMinX.contains(xx[i]) || posMinY.contains(yy[i]) || posMaxX.contains(xx[i]) || posMaxY.contains(yy[i]) ){
////            badPoints.add(i)
//        }else{
//
//        }
//    }

    fun outside(i:Int,x1:Long,x2:Long,y1:Long,y2:Long):Boolean{
        val X = xx[i]
        val Y = yy[i]

        val result = (X < x1 || X > x2 || Y < y1 || Y > y2)
        return result
    }
    var finalAnswer = Long.MAX_VALUE
    for(x1 in posMinX){
        for(y1 in posMinY){
            for(x2 in posMaxX){
                for(y2 in posMaxY){
                    var badCount = badPoints.count { outside(it,x1,x2,y1,y2) }
//                    println(badCount)
                    if(badCount <= k){
                        val xs = maxOf(1,(x2-x1) divCeil 2)
                        val ys = maxOf(1,(y2-y1) divCeil 2)

                        val tt = xs * ys

                        finalAnswer = minOf(finalAnswer,tt)
                    }

                }
            }
        }
    }
    put(finalAnswer)
    done()
}
/*
20 5
1 12 21 22
9 10 15 20
10 12 12 20
1 1 25 29
5 10 21 22
4 9 16 25
12 10 14 24
3 3 19 27
3 4 23 28
9 1 11 31
9 14 17 18
8 12 14 20
8 11 18 19
12 3 14 29
7 8 13 22
6 4 16 30
11 3 13 27
9 16 15 18
6 13 14 21
9 12 15 22




 */