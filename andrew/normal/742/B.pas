var
 a,b:Array[1..100000]of int64;
 i:longint;
 n,j,k,sc:int64;
begin
 readln(n,k);
 for i:=1 to n do begin read(a[i]); inc(b[a[i]]); end;
 for i:=1 to n do
  if (a[i] xor k>0)and( a[i] xor k<100001)then
  begin dec(b[a[i]]); inc(sc,b[a[i] xor k]);     end;
 writeln(sc);
end.