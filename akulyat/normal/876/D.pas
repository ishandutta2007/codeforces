Program Moneti;
const kar=300000; //300000
var  s:array[0..kar+1]of boolean;
     ot,mas,gl,e:array[0..kar+1]of longint;
     n,now,i,nu:longint;
     f:text; 
 
begin
//assign(f, 'output.txt');
//reset(f);
//read(f, n);
read(n);
now:=1;
ot[0]:=1;
//s[n+1]:=true;
mas[n+1]:=1;
e[n+1]:=n+1;
gl[n+1]:=n+1;
//s[0]:=true;
mas[0]:=1;
gl[0]:=1;
for i:=1 to n do
  begin
  //read(f, nu);
  read(nu);
  mas[nu]:=1;
  if mas[nu-1]=0 then
    begin
    //s[nu]:=true;
    e[nu]:=nu;
    gl[nu]:=nu;
    inc(now);
    if {s[nu+1]=true} mas[nu+1]=1 then
      begin
      //s[nu+1]:=false;
      e[nu]:=e[nu+1];
      gl[e[nu]]:=nu;
      if e[nu]=n+1 then
        dec(now);
      end;
    end else
    begin
    if {s[nu+1]=false} mas[nu+1]=0 then
      begin
      gl[nu]:=gl[nu-1];
      e[gl[nu]]:=nu;
      inc(now);
      end else
      begin
      e[gl[nu-1]]:=e[nu+1];
      gl[e[nu+1]]:=gl[nu-1];
      //s[nu+1]:=false;
      inc(now);
      if e[nu+1]=n+1 then
       now:=now-(nu-gl[n+1]+1);
      end;
    end;
  ot[i]:=now;  
  end;
for i:=0 to n do
  write(ot[i], ' ');
  //writeln;
  //writeln(ot[239069]);
  //writeln(ot[299999]);
  //writeln(ot[n]);
//close(f);


end.