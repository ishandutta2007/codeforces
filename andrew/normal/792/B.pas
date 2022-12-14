var
 a:array[1..1001]of longint;
 stn,l,ch1,ch2,sc,k,n,m,i,j:Longint;
begin
 readln(n,k);
 stn:=n;
 for i:=1 to n do a[i]:=i;
 l:=1;
 for i:=1 to k do
 begin
  if l>stn then l:=1;
  read(ch1);
  ch2:=(l+ch1)mod stn;
  if ch2=0 then ch2:=stn;
  write(a[ch2],' ');
  l:=ch2;
  a[stn+1]:=a[stn];
  for j:=ch2 to stn do a[j]:=a[j+1];
  dec(stn);
 end;
end.