var a:array['a'..'z',0..100100]of longint;
    p,i,l:longint;c:char;s:ansistring;
begin
 readln(s);l:=length(s);
 for i:=1 to l do
 begin inc(a[s[i],0]);a[s[i],a[s[i],0]]:=i;end;
 p:=0;
 for c:='z' downto 'a' do
 begin
  for i:=1 to a[c,a[c,0]] do
   if a[c,i]>p then begin write(c);p:=a[c,i];end;
 end;
end.