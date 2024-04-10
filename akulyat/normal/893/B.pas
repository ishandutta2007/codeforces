Program CodeF_E33_r_B;
var z,i,n,ot:longint;
    k:array[1..1000]of int64;
    //reb:array[1..1]of array[1..2]of longint;


begin
read(n);
k[1]:=1;
for i:=2 to 10 do
  begin
  k[i]:=k[i-1]*4;
  z:=z*2;
  if i=2 then z:=2;
  k[i]:=k[i]+z;
  end;
//writeln(k[5]);  
for i:=1 to 10 do
  begin
  if n mod k[i]=0 then
    ot:=i;
  end;

writeln(k[ot]);


end.