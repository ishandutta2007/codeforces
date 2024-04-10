Program CodeF_447_B;
const p=1000000007;
var dl,i:longint;
    tim,tim2,ot,n,m,k:int64;
    st2,stk:array[0..100]of int64;
    ma:array[0..100]of int64;
    //reb:array[1..1]of array[1..2]of longint;

Procedure Zabit(c:int64; var i:longint);
begin
i:=0;
while c>0 do
  begin
  inc(i);
  ma[i]:=c mod 2;
  c:=c div 2;
  end;

end;

begin
read(n,m,k);
st2[0]:=1;
st2[1]:=2;
 for i:=2 to 62 do
    begin
    st2[i]:=sqr(st2[i-1]) mod p;
    end;
    
{Zabit(n, dl);
  for i:=0 to dl-1 do
    if ma[i]=1 then
      ot:=(ot+st2[i])mod p;
Zabit(m, dl);
  for i:=0 to dl-1 do
    if ma[i]=1 then
      ot:=(ot+st2[i])mod p;}


{for i:=1 to 10 do
  writeln(st2[i]);}
tim:=1;
tim2:=1;
if (k=-1) and ((n mod 2=0) xor (m mod 2=0)) then writeln(0) else
  begin
  dl:=0;
  Zabit(n-1,dl);
  for i:=1 to dl do
    if ma[i]=1 then
      tim:=(tim*st2[i])mod p;
  stk[1]:=tim;
  for i:=2 to 62 do
    begin
    stk[i]:=sqr(stk[i-1]) mod p;
    end;      
  dl:=0;    
  Zabit(m-1,dl);
  for i:=1 to dl do
    if ma[i]=1 then
      tim2:=(tim2*stk[i])mod p;
  //ot:=(tim*tim2)mod p;
  //if ot=0 then inc(ot);
  //writeln(tim);
  writeln(tim2);
  //writeln(ot);
  end

end.