var
 s1:array[1..50]of ansistring;
 n,r1,l1,j1,k,i,j,l,r,ch1,ch2,sc,sc1:longint;
 s2:array[1..50]of ansistring;
 s:ansistring;
begin
 readln(n,k);
 readln(s);
 for i:=1 to n-k do
 begin
  ch1:=pos(' ',s);
  s2[i]:=copy(s,1,ch1-1);
  delete(s,1,ch1);
 end;

 s2[n-k+1]:=s;
 l1:=1;
 for i:=n downto n-k+2 do
 begin
  inc(r1);
  if r1=26 then begin inc(l1); r1:=1; end;
  s1[i]:='';
  s1[i]:=chr(l1+64)+chr(r1+96);
 end;
 for i:=n-k+1 downto 1 do
 begin
  if s2[i]='NO' then s1[i]:=s1[i+k-1] else
  begin
   inc(r1);
  if r1=26 then begin inc(l1); r1:=1; end;
  s1[i]:='';
  s1[i]:=chr(l1+64)+chr(r1+96);
  end;
 end;
 s:='';
 for i:=1 to n do s:=s+s1[i]+' ';
 delete(s,length(s),1);
 writeln(s);
end.