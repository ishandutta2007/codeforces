var
 a:array[1..500000]of longint;
 ch1,stn,max,n,i,j:longint;
begin
 readln(n);
 for i:=1 to n*2 do
 begin
  read(ch1);
  if a[ch1]=1 then dec(stn) else begin a[ch1]:=1; inc(stn); end;
  if stn>max then max:=stn;
 end;
 writeln(max);
end.