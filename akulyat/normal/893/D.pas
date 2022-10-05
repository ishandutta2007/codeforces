Program CodeF_E33_r_D;
const ki=100000;
var i,n,kol:longint;
    t:array[0..ki+10]of longint;
    s,max:array[0..ki+10]of longint;
    //reb:array[1..1]of array[1..2]of longint;
    d,dop:longint;

begin
read(n,d);
s[0]:=0;
for i:=1 to n do
  begin
  read(t[i]);
  s[i]:=s[i-1]+t[i];
  end;
for i:=1 to n do
  if s[i]>d then
    begin
    writeln(-1);
    exit;
    end;
    
max[n]:=s[n];
for i:=n-1 downto 1 do
  if s[i]>max[i+1]  
    then max[i]:=s[i]
    else max[i]:=max[i+1];
    
dop:=0;    
for i:=1 to n do
  if t[i]=0 then
    begin
    if s[i-1]+dop<0 then
      begin
      dop:=d-max[i];
      inc(kol);
      end;    
     if s[i-1]+dop<0 then
       begin
       writeln(-1);
       exit;
       end;
    end;    
writeln(kol);


end.