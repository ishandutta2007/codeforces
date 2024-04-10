var a:array['a'..'z']of longint;
    x:array[1..1100]of boolean;
    s:ansistring;
    c,t:char;
    log:boolean;
    l,i,f,r,q:longint;
begin
 readln(s);l:=length(s);q:=1;
 for i:=1 to l do
  inc(a[s[i]]);
 for i:=2 to l do
 begin
  if not(x[i]) then
  begin
   f:=i*2;
   if f>l then inc(q);
   while f<=l do
   begin
    x[f]:=true;
    f:=f+i;
   end;
  end;
 end;
 log:=false;
 r:=l-q;
 for c:='a' to 'z' do
  if a[c]>=r then begin log:=true;t:=c;end;
 if not(log) then begin writeln('NO');halt(0);end;
 writeln('YES');
 for c:='a' to 'z' do if (a[c]<>r)and(a[c]<>0) then begin dec(a[c]);write(c);break;end;
 for i:=2 to l do
  if not(x[i])and(i*2>l) then
  begin 
   while((a[c]=r)and(c=t))or(a[c]=0) do inc(c);dec(q);dec(a[c]);write(c);
  end else
  begin
   dec(r);dec(a[t]);write(t);
  end;
end.