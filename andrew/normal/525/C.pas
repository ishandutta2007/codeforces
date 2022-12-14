var
 a:array[0..1000000]of int64;
 sc,ch1,dp,dp1,k:int64;
 i,n,j:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(ch1);
  inc(a[ch1]);
 end;

 for i:=1000000 downto 2 do if(a[i] mod 2=1)then
 begin
  dec(a[i]);
  if(a[i-1]>0)then inc(a[i-1]);
 end;

 for i:=1000000 downto 2 do if a[i]<>0 then
 begin
  ch1:=int64(i);
  if dp=2 then begin sc:=sc+dp1*ch1; dp1:=0; dp:=0; dec(a[i],2); end;
   k:=a[i] div 4;
   sc:=sc+k*(ch1*ch1);
   a[i]:=a[i]-(k*4);
   if a[i]>=2 then begin dp:=2; dp1:=ch1; end;
 end;
 writeln(sc);
end.