{$r-,q-,i-,s-,o+}
var s:ansistring;
    a:array[1..1000000]of ansistring;
    i,f,b,l:longint;
begin
 readln(s);
 l:=length(s);
 f:=0;b:=1;
 for i:=1 to l do
  if s[i]='.' then begin inc(f);a[f]:=copy(s,b,i-b+1);b:=i+1;end;
 a[f+1]:=copy(s,b,l-b+1);
 if (length(a[1])>9)or(length(a[1])=1) then begin writeln('NO');halt(0);end;
 for i:=2 to f do
  if (length(a[i])>12)or(length(a[i])<3) then begin writeln('NO');halt(0);end;
 if (length(a[f+1])>3)or(length(a[f+1])=0) then begin writeln('NO');halt(0);end;
 if f=0 then begin writeln('NO');halt(0);end;
 writeln('YES');
 write(a[1]);
 for i:=2 to f do
 begin
  if length(a[i])=12 then begin writeln(a[i][1],a[i][2],a[i][3]);delete(a[i],1,3);end else
  if length(a[i])=11 then begin writeln(a[i][1],a[i][2]);delete(a[i],1,2);end else
  begin writeln(a[i][1]);delete(a[i],1,1);end;
  write(a[i]);
 end;
 writeln(a[f+1]);
end.