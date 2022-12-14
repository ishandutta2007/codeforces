var
 k,n,i,a:longint;
begin
 readln(k,n);
 n:=240-n;
 a:=0;
 for i:=1 to k do 
 begin
  a:=a+i*5;
  if a>n then begin writeln(i-1); halt; end;
 end;
 writeln(k);
end.