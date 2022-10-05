Program CodeF_GB_2017_A;
var i,n,l:longint;
    m:array[1..1]of longint;
    //reb:array[1..1]of array[1..2]of longint;
    s:string;

begin
readln(s);
l:=length(s);
n:=0;
for i:=1 to l do
  begin
  if (s[i]='a') or (s[i]='e') or (s[i]='i') or (s[i]='o') or (s[i]='u') or
     (s[i]='1') or (s[i]='3') or (s[i]='5') or (s[i]='7') or (s[i]='9') then
     inc(n);  
  end;
writeln(n);




end.