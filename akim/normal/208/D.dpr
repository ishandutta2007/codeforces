var a:array[1..50]of int64;
    b:array[1..5]of int64;
    x:array[1..5]of int64;
    s:int64;
    i,n:longint;
begin
 readln(n);s:=0;
 for i:=1 to n do
  read(a[i]);
 for i:=1 to 5 do
  read(b[i]);
 for i:=1 to n do
 begin
  s:=s+a[i];
  if s div b[5]>0 then begin x[5]:=x[5]+s div b[5];s:=s mod b[5];end;
  if s div b[4]>0 then begin x[4]:=x[4]+s div b[4];s:=s mod b[4];end;
  if s div b[3]>0 then begin x[3]:=x[3]+s div b[3];s:=s mod b[3];end;
  if s div b[2]>0 then begin x[2]:=x[2]+s div b[2];s:=s mod b[2];end;
  if s div b[1]>0 then begin x[1]:=x[1]+s div b[1];s:=s mod b[1];end;
 end;
 for i:=1 to 4 do
  write(x[i],' ');
 writeln(x[5]);
 writeln(s);
end.