var
 s:ansistring;
 ch1,ch2,ch3,ch4,ch5,ch6,i,j,k:longint;
begin
 readln(s);
 while length(s)>2 do delete(s,1,1);
 val(s,k);
 k:= k mod 4;
 ch1:=1;
 ch2:=1;
 ch3:=1;
 ch4:=1;
 for i:=1 to k do ch2:=ch2*2;
 for i:=1 to k do ch3:=ch3*3;
 for i:=1 to k do ch4:=ch4*4;
 writeln((ch1+ch2+ch3+ch4)mod 5);
end.